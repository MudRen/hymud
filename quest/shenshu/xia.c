#include <ansi.h>
inherit ITEM;
#include "/quest/givetaskgift.c"
void create()
{
    set_name("����ˮ�����²�"NOR, ({ "xiabook" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("no_put", 1);
            set("material", "paper");
            set("long", "һ��������ϲ��ɵľ�ᣬ�������(chayue)����������\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
}
int do_cha()
{
	object me,corpse,ob;
	int exp,pot,score;
	me =this_player();
	exp = 12900+random(2900);
	             pot = exp*2/3;
             score = random(20)+20;

     	      message_vision("$N��ϸ�ز�����һ��"+this_object()->query("name")+"��\n", me);
        addnl(me,"exp",exp);
        addnl(me,"score",score);
if (random(3)==0)
{
        corpse=new("/clone/gem/gem");
if (corpse->query("level") >4
&& random(3)>0)
{
        corpse=new("/clone/gem/gem");
}

if (random(3)==1)
{
        ob=new(__DIR__"sdan");
        ob->move(me);
message("channel:chat", HIC"���������š�"GRN + me->query("name")+"�õ�һ��"+HIY":" + ob->query("name")+HIG"����\n"NOR,users() );
}

message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "ͨ�����������ҵ���һ��"+corpse->query("name")+HIM"!"NOR"��\n", users());
             corpse->move(me);
}

	destruct(this_object());
return 1;
}
