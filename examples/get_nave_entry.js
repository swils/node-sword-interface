const NodeSwordInterface = require('../index.js');
var interface = new NodeSwordInterface();

async function installNave() {
  console.log("Updating repository configuration ...");
  await interface.updateRepositoryConfig();

  console.log("Installing Nave module");
  // Install the King James Version (Uses the internet connection to download and install the module)
  await interface.installModule('Nave');
}

installNave().then(() => {
  console.log('Installation of Nave completed!');

  // Do something with the Nave module
  var entry = interface.getRawModuleEntry('Nave', 'Jacob');
  console.log(entry);
});