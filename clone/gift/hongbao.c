// ���

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"���"NOR, ({"hong bao", "bao", "hong"}));
	set_weight(10);
set("no_drop", 1);
set("no_put", 1);
    set("no_bug", 1);
set("liwu",1);
    set("no_steal", 1);
    set("no_get", 1);
    set("value", 0);
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 0);
    set("value", 0);
		set("long", "һ���ú�ֽ�������ɵ�"+HIR"�����"NOR+"�ƺ�����˺��(opengift)��\n");
		set("unit", "��");
	}
}
  void init()
{
  add_action("do_open","opengift");
}
int do_open()
{
object ob;
	int exp,pot,score;
object corpse;
        object me = this_player();
exp = 888+random(888);
pot = exp*2/3;
score=18;
me->add("combat_exp",exp);
me->add("potential",pot);
me->add("max_neili",score);


	this_player()->start_busy(50);
	message_vision("$N���˺����ֻ�����Լ��ֱ�������һЩ !\n", this_player());
tell_object(me,HIY"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"������\n"NOR);

	destruct(this_object());
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}