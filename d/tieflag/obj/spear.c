#include <weapon.h>
#include <ansi.h>
inherit CLUB; 
void create()
{
        set_name(HIR"����ǹ"NOR, ({ "spear" }) );
        set_weight(36400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "
����ǹ��һ�������ߴ����֣�����ʮ����������Ǯ��\n
��˵�����������������������ʹ�˵�е��������ֱ����ϳɣ�combine���ġ�\n");
                set("value", 4000);
                set("material", "steel");
                set("wield_msg", "$Nһ���ֳ���һ��$n��\n");
                set("unwield_msg", "$N�����е�$n������¡�\n");
        }
        ::init_club(660);
} 
void init()
{
  if(this_player()==environment())
  add_action("do_combine","combine");
} 
int do_combine()
{
int i,bk=0,cs=0,le=0,lo=0,pe=0,sp=0,il=0;
object commcase,me, *inv;
object bknife,csword,leavehook,lovering,peacock,spear,illquan;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
                {
                        if(base_name(inv[i]) == __DIR__"csword") {cs = 1; csword = inv[i];}
                        if(base_name(inv[i]) == __DIR__"leavehook") {le = 1; leavehook = inv[i];}
                        if(base_name(inv[i]) == __DIR__"lovering") {lo = 1;  lovering = inv[i];}
                        if(base_name(inv[i]) == __DIR__"spear") {sp = 1; spear = inv[i];}
                        i++;
                }
                        if(me->query_skill("ill-quan")>=10) {il = 1;}
if( bk && cs && le && lo && pe && sp && il )
{
        
        bknife->move(environment(me));destruct(bknife);
        csword->move(environment(me));destruct(csword);
        leavehook->move(environment(me));destruct(leavehook);
        lovering->move(environment(me));destruct(lovering);
        peacock->move(environment(me));destruct(peacock);
        message_vision("$N�����еļ���������ϸ�о���һ����
���ò�άĦȭ�շ����ĵ��������ɣ�������������һ�����ӡ�\n",me);
        commcase = new(__DIR__"commcase");
        commcase->move(me);
        if(!me->query("m_success/������"))
        {
                me->set("m_success/������",1);
                me->add("score",700); 
        }
        spear->move(environment(me));destruct(spear);
}
else 
message_vision("$N�����еļ���������ϸ�о���һ����\n",this_player()); 
return 1;
}    
