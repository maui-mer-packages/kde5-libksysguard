/*  This file is part of the KDE project

    Copyright (C) 2007 John Tapsell <tapsell@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "processes_remote_p.h"
#include "process.h"

#include <QString>
#include <QSet>

#include <klocale.h>
#include <kdebug.h>





namespace KSysGuard
{

  class ProcessesRemote::Private
  {
    public:
      Private() {;}
      ~Private() {;}
      QString host;
    };
ProcessesRemote::ProcessesRemote(const QString &hostname) : d(new Private())
{
  d->host = hostname;
  kDebug() << "Remote hosti " << hostname;
}


long ProcessesRemote::getParentPid(long pid) {
    return 0;
}
bool ProcessesRemote::updateProcessInfo( long pid, Process *process)
{
    return false;
}

QSet<long> ProcessesRemote::getAllPids( )
{
    emit runCommand("ps?", 0);
    QSet<long> pids;
    return pids;
}

bool ProcessesRemote::sendSignal(long pid, int sig) {
    return false;
}
bool ProcessesRemote::setNiceness(long pid, int priority) {
    return false;
}

bool ProcessesRemote::setIoNiceness(long pid, int priorityClass, int priority) {
    return false; //Not yet supported
}

bool ProcessesRemote::setScheduler(long pid, int priorityClass, int priority) {
    return false;
}

bool ProcessesRemote::supportsIoNiceness() {
    return false;
}

long long ProcessesRemote::totalPhysicalMemory() {
    return 0;
}
long ProcessesRemote::numberProcessorCores() {
    return 0;
}

void ProcessesRemote::answerReceived( int id, const QList<QByteArray>& answer ) {
    kDebug() << "Answer received in remote ";
}

ProcessesRemote::~ProcessesRemote()
{
    delete d;
}

}

#include "processes_remote_p.moc"

