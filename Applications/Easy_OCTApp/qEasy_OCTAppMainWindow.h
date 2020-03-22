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

#ifndef __qEasy_OCTAppMainWindow_h
#define __qEasy_OCTAppMainWindow_h

// Easy_OCT includes
#include "qEasy_OCTAppExport.h"
class qEasy_OCTAppMainWindowPrivate;

// Slicer includes
#include "qSlicerMainWindow.h"

class Q_EASY_OCT_APP_EXPORT qEasy_OCTAppMainWindow : public qSlicerMainWindow
{
  Q_OBJECT
public:
  typedef qSlicerMainWindow Superclass;

  qEasy_OCTAppMainWindow(QWidget *parent=0);
  virtual ~qEasy_OCTAppMainWindow();

public slots:
  void on_HelpAboutEasy_OCTAppAction_triggered();

protected:
  qEasy_OCTAppMainWindow(qEasy_OCTAppMainWindowPrivate* pimpl, QWidget* parent);

private:
  Q_DECLARE_PRIVATE(qEasy_OCTAppMainWindow);
  Q_DISABLE_COPY(qEasy_OCTAppMainWindow);
};

#endif
