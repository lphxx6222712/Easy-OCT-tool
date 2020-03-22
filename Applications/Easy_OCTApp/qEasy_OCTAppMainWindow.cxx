/*==============================================================================

  Copyright (c) Kitware, Inc.

  See http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Julien Finet, Kitware, Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// Easy_OCT includes
#include "qEasy_OCTAppMainWindow.h"
#include "qEasy_OCTAppMainWindow_p.h"

// Qt includes
#include <QDesktopWidget>

// Slicer includes
#include "qSlicerApplication.h"
#include "qSlicerAboutDialog.h"
#include "qSlicerMainWindow_p.h"
#include "qSlicerModuleSelectorToolBar.h"

//-----------------------------------------------------------------------------
// qEasy_OCTAppMainWindowPrivate methods

qEasy_OCTAppMainWindowPrivate::qEasy_OCTAppMainWindowPrivate(qEasy_OCTAppMainWindow& object)
  : Superclass(object)
{
}

//-----------------------------------------------------------------------------
qEasy_OCTAppMainWindowPrivate::~qEasy_OCTAppMainWindowPrivate()
{
}

//-----------------------------------------------------------------------------
void qEasy_OCTAppMainWindowPrivate::init()
{
  Q_Q(qEasy_OCTAppMainWindow);
  this->Superclass::init();
}

//-----------------------------------------------------------------------------
void qEasy_OCTAppMainWindowPrivate::setupUi(QMainWindow * mainWindow)
{
  qSlicerApplication * app = qSlicerApplication::application();

  //----------------------------------------------------------------------------
  // Add actions
  //----------------------------------------------------------------------------
  QAction* helpAboutSlicerAppAction = new QAction(mainWindow);
  helpAboutSlicerAppAction->setObjectName("HelpAboutEasy_OCTAppAction");
  helpAboutSlicerAppAction->setText("About " + app->applicationName());

  //----------------------------------------------------------------------------
  // Calling "setupUi()" after adding the actions above allows the call
  // to "QMetaObject::connectSlotsByName()" done in "setupUi()" to
  // successfully connect each slot with its corresponding action.
  this->Superclass::setupUi(mainWindow);

  //----------------------------------------------------------------------------
  // Configure
  //----------------------------------------------------------------------------
  mainWindow->setWindowIcon(QIcon(":/Icons/Medium/DesktopIcon.png"));

  QPixmap logo(":/LogoFull.png");
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
  qreal dpr = sqrt(qApp->desktop()->logicalDpiX()*qreal(qApp->desktop()->logicalDpiY()) / (qApp->desktop()->physicalDpiX()*qApp->desktop()->physicalDpiY()));
  logo.setDevicePixelRatio(dpr);
#endif
  this->LogoLabel->setPixmap(logo);

  // Hide the toolbars
  this->MainToolBar->setVisible(false);
  //this->ModuleSelectorToolBar->setVisible(false);
  this->ModuleToolBar->setVisible(false);
  this->ViewToolBar->setVisible(false);
  this->MouseModeToolBar->setVisible(false);
  this->CaptureToolBar->setVisible(false);
  this->ViewersToolBar->setVisible(false);
  this->DialogToolBar->setVisible(false);

  // Hide the menus
  //this->menubar->setVisible(false);
  //this->FileMenu->setVisible(false);
  //this->EditMenu->setVisible(false);
  //this->ViewMenu->setVisible(false);
  //this->LayoutMenu->setVisible(false);
  //this->HelpMenu->setVisible(false);

  // Hide the modules panel
  //this->PanelDockWidget->setVisible(false);
  this->DataProbeCollapsibleWidget->setCollapsed(true);
  this->DataProbeCollapsibleWidget->setVisible(false);
  this->StatusBar->setVisible(false);
}

//-----------------------------------------------------------------------------
// qEasy_OCTAppMainWindow methods

//-----------------------------------------------------------------------------
qEasy_OCTAppMainWindow::qEasy_OCTAppMainWindow(QWidget* windowParent)
  : Superclass(new qEasy_OCTAppMainWindowPrivate(*this), windowParent)
{
  Q_D(qEasy_OCTAppMainWindow);
  d->init();
}

//-----------------------------------------------------------------------------
qEasy_OCTAppMainWindow::qEasy_OCTAppMainWindow(
  qEasy_OCTAppMainWindowPrivate* pimpl, QWidget* windowParent)
  : Superclass(pimpl, windowParent)
{
  // init() is called by derived class.
}

//-----------------------------------------------------------------------------
qEasy_OCTAppMainWindow::~qEasy_OCTAppMainWindow()
{
}

//-----------------------------------------------------------------------------
void qEasy_OCTAppMainWindow::on_HelpAboutEasy_OCTAppAction_triggered()
{
  qSlicerAboutDialog about(this);
  about.setLogo(QPixmap(":/Logo.png"));
  about.exec();
}
