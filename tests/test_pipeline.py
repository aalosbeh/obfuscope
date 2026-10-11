"""Lightweight sanity tests for the ObfuScope pipeline (run with pytest)."""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))

from obfuscope.features import extract_features, feature_names, vectorize
from obfuscope.labels import parse_family, technique_of, sub_technique_of
from obfuscope.make_grid import enumerate_cells
from obfuscope.models import build_model, MODEL_NAMES


def test_feature_vector_length_is_stable():
    a = extract_features("int main(){return 0;}")
    b = extract_features("int f(){int x=0x42; if(0){goto L;} while(x){x--;} return x;}")
    assert len(vectorize(a)) == len(vectorize(b)) == len(feature_names()) == 61


def test_obfuscation_indicators_fire():
    f = extract_features("int f(){int a=1; if(0){a=a^0x13;} magic1=5; goto L; L: return a;}")
    assert f["obf_opaque_pred"] >= 1
    assert f["obf_goto"] >= 1
    assert f["n_xor_op"] >= 1


def test_label_parsing():
    p = "Testing/aef00c9219bc4b1dbb406b010f1e410f_ClassicShell.exe/code_based_variants/x_real.c"
    assert technique_of(p) == "code_based_variants"
    assert parse_family("aef00c9219bc4b1dbb406b010f1e410f_ClassicShell.exe") == "ClassicShell"
    assert sub_technique_of("control_flow_flattened_real.c") == "control_flow_flattened"


def test_grid_is_deduplicated():
    cells = enumerate_cells()
    ids = [c.cell_id for c in cells]
    assert len(ids) == len(set(ids))
    assert len(cells) > 0


def test_all_models_build():
    for name in MODEL_NAMES:
        assert build_model(name, seed=0) is not None


if __name__ == "__main__":
    for fn in [test_feature_vector_length_is_stable, test_obfuscation_indicators_fire,
               test_label_parsing, test_grid_is_deduplicated, test_all_models_build]:
        fn()
        print("PASS", fn.__name__)
    print("all tests passed")
