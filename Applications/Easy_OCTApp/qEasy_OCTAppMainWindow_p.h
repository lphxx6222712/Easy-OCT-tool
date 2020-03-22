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

#ifndef __qEasy_OCTAppMainWindow_p_h
#define __qEasy_OCTAppMainWindow_p_h

// Easy_OCT includes
#include "qEasy_OCTAppMainWindow.h"

// Slicer includes
#include "qSlicerMainWindow_p.h"

//-----------------------------------------------------------------------------
class Q_EASY_OCT_APP_EXPORT qEasy_OCTAppMainWindowPrivate
  : public qSlicerMainWindowPrivate
{
  Q_DECLARE_PUBLIC(qEasy_OCTAppMainWindow);
public:
  typedef qSlicerMainWindowPrivate Superclass;
  qEasy_OCTAppMainWindowPrivate(qEasy_OCTAppMainWindow& object);
  virtual ~qEasy_OCTAppMainWindowPrivate();

  virtual void init();
  /// Reimplemented for custom behavior
  virtual void setupUi(QMainWindow * mainWindow);
};

#endif
