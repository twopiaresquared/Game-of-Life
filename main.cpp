#include <iostream>
#include "pyvis/PythonVisualizer.h"
#include <vector>

int main() {
  using Grid = std::vector<std::vector<int>>;
  using GridStates = std::vector<Grid>;

  const int rows = 100;
  const int columns = 100;
  
  GridStates data;
  Grid grid;

  // Grid initialized.
  for(int i = 0; i < rows; i++) {
    grid.push_back(std::vector<int>(columns, 0));
  }

  // Graphing code.
  py::PythonVisualizer pyvis({".."});
  auto figure = pyvis.make_new_figure("Conway's Game of Life");
  auto im = pyvis.image(figure, data[0]);
  auto slider = pyvis.slider(im, "Frame", 0, data.size(), py::kwarg("image", data));
  auto layout = pyvis.layout(figure, slider);
  pyvis.generate_html(layout, "conway.html");

  return 0;
}
