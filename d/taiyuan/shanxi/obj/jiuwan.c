#include <ansi.h>
inherit ITEM; 
//void apply(string confirm, object me);
void create()
{
    set_name(HIW "����" NOR,({"wan"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("lore",1);
                 set("no_pawn",1);
                set("material", "wood");
                set("long", "���䲻������������ȴ�����������ݴ�����\n");
                }
} 
void init()
{
        if(this_player()==environment())
        add_action("do_drink","drink");
        add_action("do_throw", "throw");
} 
int do_drink(string arg)
{
        object me, obj;
        me = this_player();
        if (!arg)
                return notify_fail("��Ҫ��ʲô��\n");
        if (arg != "wan")
                return notify_fail("��Ҫ��ʲô��\n");
        if (query("used")) 
                return notify_fail(this_object()->name()+"�Ѿ����ȹ��ˡ�\n");  
        message_vision("$N�ƺ���վ��վ�����ˣ�����֮ʱ��Ȼ���ִ�������������ơ�\n",me);
        message_vision("$Nһ����������ȥ�������ѱ�����ҵ�һ����������������������\n",me);
        message_vision("�ۼ��$N������׻��и��֡�\n",me);
        this_object()->set("long","�ȸ��˵ľ��룬��׾�Ȼд��һ����ˤ����(throw)��\n");
       if (!me->query_condition("killer") && !me->query_condition("psgc") )
        {
me->set("qi",me->query("max_qi"));
me->set("jing",me->query("max_jing"));
me->set("neili",me->query("max_neili"));
      }
        me->start_busy(3);
        set("used",1);   //��ղ��������˷ֺ�
        return 1;
}
int do_throw(string arg)
{
	if(!arg || arg != "wan" || arg != "����" ) return notify_fail("��Ҫˤʲô��\n");  //add by xiaolang
	message_vision("$N���������еľ���ˤ�˳�ȥ����ž����һ���������Ƴ���Ƭ.....\n",this_player());   //add by xiaolang
        destruct(this_object());
          return 1;
} 
// add by xiaolang
/*int do_look(string arg)
{
	object me;
	me = this_player();
	if(query("used")
	*/