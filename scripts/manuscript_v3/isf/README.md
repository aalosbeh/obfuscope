# Figures for the Information Systems Frontiers version

The Springer Nature template (`sn-jnl`) has a text width of 372 pt (5.15 in), and
Springer asks for figure lettering of 8 to 12 pt. The figures of the submitted
article were produced as follows.

- Fig. 1 (pipeline): `Fig1.tex` in this folder, compiled with XeLaTeX
  (`tectonic Fig1.tex`). It needs the Arial font.
- Figs. 2 to 4 (open-set results, sibling axis, simulation) come from
  `make_figures.py` with the width and the smallest font size set through the
  environment:

```bash
OBF_FIG_WIDTH=5.15 OBF_FIG_MIN_PT=8 python scripts/manuscript_v3/make_figures.py \
    --out isf_figs --no-tectonic --only fig3-openset fig4-sibling-axis fig5-simulation
```

The files `fig3-openset.pdf`, `fig4-sibling-axis.pdf` and `fig5-simulation.pdf`
are Figs. 2, 3 and 4 of the article. Without the two variables the script keeps
its defaults (5.47 in, 7 pt), which give the figures of the earlier ACM layout.
