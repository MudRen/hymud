// shutdown.c

#include <net/daemons.h>

inherit F_CLEAN_UP;
inherit __DIR__"user_weapond.c";
int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i,tp,lv,lb;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ����ʹ��!\n");

//weaponmake(i,tp,lv);
//iΪ����,tpΪ������0-8,lvΪ�ȼ�1-6

//armormake(i,tp,lv);
//iΪ����,tpΪ������0-9,lvΪ�ȼ�1-6
//lbΪ0Ϊweapon Ϊ1Ϊarmor
lb=0;
tp=8;
for(tp = 0; tp<=8; tp++) {

//lv1
lv=1;
				for(i = 0; i<100; i++) {
if (lb==0) weaponmake(i,tp,lv); else if (lb==1) armormake(i,tp,lv);
					}
//lv2
lv=2;
				for(i = 100; i<200; i++) {
if (lb==0) weaponmake(i,tp,lv); else if (lb==1) armormake(i,tp,lv);
					}
//lv3
lv=3;
				for(i = 200; i<300; i++) {
if (lb==0) weaponmake(i,tp,lv); else if (lb==1) armormake(i,tp,lv);
					}

//lv4
lv=4;
				for(i = 300; i<400; i++) {
if (lb==0) weaponmake(i,tp,lv); else if (lb==1) armormake(i,tp,lv);
					}
//lv5
lv=5;
				for(i = 400; i<450; i++) {
if (lb==0) weaponmake(i,tp,lv); else if (lb==1) armormake(i,tp,lv);
					}
//lv6
lv=6;
				for(i = 450; i<480; i++) {
if (lb==0) weaponmake(i,tp,lv); else if (lb==1) armormake(i,tp,lv);
					}
					

}
					
	return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: shutdown
 
ˢ���������ϵͳ
 
HELP
);
        return 1;
}
 
