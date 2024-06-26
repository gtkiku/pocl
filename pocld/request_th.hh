/* request_th.hh - pocld thread that listens for incoming commands

   Copyright (c) 2018 Michal Babej / Tampere University of Technology
   Copyright (c) 2019-2023 Jan Solanti / Tampere University

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to
   deal in the Software without restriction, including without limitation the
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
*/

#ifndef POCL_REMOTE_REQUEST_TH_HH
#define POCL_REMOTE_REQUEST_TH_HH

#include "common.hh"
#include "traffic_monitor.hh"
#include "virtual_cl_context.hh"

#ifdef __GNUC__
#pragma GCC visibility push(hidden)
#endif

class RequestQueueThread {
  std::atomic_int *fd;
  VirtualContextBase *virtualContext;
  std::thread io_thread;
  ExitHelper *eh;
  std::string id_str;
  TrafficMonitor *netstat;

public:
  RequestQueueThread(std::atomic_int *fd, VirtualContextBase *c, ExitHelper *eh,
                     TrafficMonitor *tm, const char *id_str);

  ~RequestQueueThread();

  void readThread();
};

typedef std::unique_ptr<RequestQueueThread> RequestQueueThreadUPtr;

#ifdef __GNUC__
#pragma GCC visibility pop
#endif

#endif
