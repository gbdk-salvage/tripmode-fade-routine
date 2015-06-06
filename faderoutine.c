void fade_in(UWORD *org_p, UWORD *wrk_p, UBYTE fade_from, UWORD delay_count)
{
/* Supply the original palette array (32 UWORDS) in org_p,
   and a working palette array (32 UWORDS) in wrk_p. This working palette
   should ideally be a global array to be most efficient. Any data in it is
   destroyed.
   If fade_from is 0, it fades in from black. If 1, from white
*/

 UBYTE i,x;
 UWORD bit_mask;

 bit_mask = 0x0421; /* 0000010000100001 */
 if (fade_from == 0) { /* fade from black */
   for (i=0; i < 5; i++) { /* 5 bits per color */
   for(x=0;x<32;x++) {
   wrk_p[x] = org_p[x] & bit_mask;
   }
   bit_mask |= (bit_mask << 1);
   set_bkg_palette(0,8, &wrk_p[0] );
   delay(delay_count);
   }
 }
 else {
  for (i=0; i < 5; i++) {
   for(x=0;x<32;x++) {
   wrk_p[x] = org_p[x] | (0x7FFF & ~bit_mask);
   }
   bit_mask |= (bit_mask << 1);
   set_bkg_palette(0,8, &wrk_p[0] );
   delay(delay_count);
   }
 }
}

void fade_out(UWORD *org_p, UWORD *wrk_p, UBYTE fade_to, UWORD delay_count)
{
 /* The same params as fade_in */

 UBYTE i,x;
 UWORD bit_mask;

 bit_mask = 0x4210; /* 0100001000010000 */
 if (fade_to == 0) {
  for (i=0; i < 5; i++) {
   for(x=0;x<32;x++) {
   wrk_p[x] = org_p[x] & ~bit_mask;
   }
   bit_mask |= (bit_mask >> 1);
   set_bkg_palette(0,8, &wrk_p[0] );
   delay(delay_count);
   }
 }
 else {
  bit_mask = 0x4210;
  for (i=0; i < 5; i++) {
   for(x=0;x<32;x++) {
   wrk_p[x] = org_p[x] | bit_mask;
   }
   bit_mask |= (bit_mask >> 1);
    set_bkg_palette(0,8, &wrk_p[0] );
   delay(delay_count);
   }
 }
}


