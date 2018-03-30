#include "PointGreyInference.h"
#include "ConfigParser.h"


int main(int argc, char* argv[])
{
  std::string fname;
  if (argc < 2) {
    printf("No config file, using default inference parameters\n");
    fname = "";
  } else {
    fname = std::string(argv[1]);
  }
  ConfigParser config(fname);

  config.addNumericParam("nangles", 200);
  config.addNumericParam("ncircles", 20);
  config.addNumericParam("rstep", 12);
  config.addNumericParam("lambda", 10);
  config.addNumericParam("beta", 100);
  config.addNumericParam("alpha", 0.8);
  config.addNumericParam("disp_rollup", 0);

  config.parse();

  PointGreyInference pginf(
      (int) config.getNumericParam("nangles"),
      (int) config.getNumericParam("ncircles"),
      (float) config.getNumericParam("rstep"),
      config.getNumericParam("lambda"),
      config.getNumericParam("beta"),
      config.getNumericParam("alpha"),10);

  pginf.processStream((bool) config.getNumericParam("disp_rollup"));

  return 0;
}
