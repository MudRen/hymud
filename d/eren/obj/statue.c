#include <ansi.h>
inherit ITEM;
string statuedesc(); 
void create()
{
    set_name("����", ({"statue","����"}) );
    set_weight(200000);
    set("no_get",1);
    set("no_shown",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: statuedesc :));
                set("unit", "��");
                set("value", 3000);
              }
    
} 
void init()
{
        add_action("do_turn","turn");
} 
string statuedesc()
{
        object me;
        string msg;
        me = this_player();
        msg="һ�����˸ߵ�������һ���ִ�ŵ���׺��ӣ�������ī���Ũü�������ȧ
�ǣ�һֻ�ݹ���᾵Ĵ���ץ�ű�����ÿ��õ�������\n";
        if (me ->query("marks/���˿�")||me->query("marks/֩����˿�"))
        {       
                msg+="��ϸ��ȥ�������İ���(handle)�ƺ�����ת��(turn)��\n";
        }
        return msg;
} 
int do_turn( string arg){
        object me, room;
        
        me=this_player();

        if (!arg || (arg!="����" && arg!="handle")) {
                tell_object(me,"��Ҫתʲô��\n");
                return 1;
                }
        if (me->query("combat_exp")<2500000)
                tell_object(me,"��Ѿ�ȫ����������˿������Ҳ�����书̫���˰ɡ�\n");
        message_vision  (YEL"$N����һ�⽣����ֻ��һ��¸µ�������$N���³�����һ���󶴡�\n"NOR,me);
        room = find_object("/d/eren/tocave");
        if(!objectp(room)) 
                room = load_object("/d/eren/tocave"); 
        message_vision(HIR"һ�����У�$N����ֱ׹��ȥ��\n"NOR,me);
        message("vision",HIG"�Ϸ��ֵ���һ����������æ���ҵ�ץס������ߵ�������\n"NOR,room);
        me->move(room);
        return 1;
}
