// SPDX-License-Identifier: BSD-2-Clause
/*
Copyright 2010-2011 Bernard Parent

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of
   conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list
   of conditions and the following disclaimer in the documentation and/or other
   materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "fluid.h"
#include "fluid_source.h"
#include <model/metrics/_metrics.h>
#include <model/_model.h>
#include <model/share/fluid_share.h>





void find_Sstar(np_t *np, gl_t *gl, long l, flux_t S){
  long flux;
  long dim;
  flux_t Saxi;

  for (flux=0; flux<nf; flux++){
    S[flux]=0.0;
  }
  S[nd+1]=np[l].bs->Qadd*_Omega(np[l],gl);
  for (dim=0; dim<nd; dim++) {
    S[1+dim]=np[l].bs->Fbody[dim]*_Omega(np[l],gl);
    S[1+nd]+=np[l].bs->Fbody[dim]*_V(np[l],dim)*_Omega(np[l],gl);
  }

  find_Saxi(np,gl,l,Saxi);
  for (flux=0; flux<nf; flux++) S[flux]+=_Omega(np[l],gl)*(Saxi[flux]);
}


void test_dSchem_dU(np_t *np, gl_t *gl, long l){
  wfprintf(stdout,"\n\nThe NavierStokesPerfect() module can not be used with chemical solvers.\n");
}




void find_dSstar_dUstar(np_t *np, gl_t *gl, long l, sqmat_t dSstar_dUstar){
  long col,row;
  sqmat_t dSaxidU;
 
  find_dSaxi_dU(np,gl,l,dSaxidU);
  
  for (row=0; row<nf; row++){
    for (col=0; col<nf; col++){
      dSstar_dUstar[row][col]=dSaxidU[row][col];
    }
  }
#ifndef TEST
  for (row=0; row<nf; row++) dSstar_dUstar[row][row]=min(0.0e0,dSstar_dUstar[row][row]);
#endif

}

