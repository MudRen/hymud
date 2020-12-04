// Room: /u/diabio/feitian/feitian/haigang.c
#include <ansi.h>
#include <room.h>
#include <command.h>
inherit ROOM;
int consider_lv(object ob,int a);

void create()
{
  set ("short", "����");
  set ("long", @LONG
�����Ǿ���Ψһͨ����صĺ���,�����ۼ�֮����һƬ����.
����Ļ���Ĳ���Ϊ���ܰ�ȫ�������ŵĻ�.�����Ǳ��ƺ��д�
�����ߣ����ϵ������ڴ���ߺ��~~~Ҫȥ�����Ŀ���ϴ���.
���ϱ���һ�������������Ŀ촬��ֱͨȪ�ݡ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guangchang",
  "south" : "/d/quanzhou/haigang",
]));
  set("outdoors", "feitian");
  setup();
}
void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object me, ob,room,obj;
	int level;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ ������ȥ��\n" ) ;
         return 1 ;
       }
    if (!room=find_object("/d/feitian/dahai"))
    room=load_object("/d/feitian/dahai");
    me = this_player () ;
    message_vision("���ϴ�һ�������ϴ���æ����һ��������ඣ�\n", me);
    message_vision("�������𷫣�����������ȥ��\n", me);
		obj=present(me->query("id")+" "+"wulin renwu", environment(me));
    if (obj)     obj->move (room);    
    me->move(room) ;
    tell_object(me, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
if (random(10) > 7)
{
		message_vision(HIB"ͻȻ�����ϳ�����һ�㺣������һ�����������˴�.......\n"NOR, me);
		message_vision(HIB"�������һ�������е���ͨͨ������������������\n"NOR, me);

		ob = new(__DIR__"npc/wokou");
              ob->set("combat_exp",me->query("combat_exp") * 8 / 10);
		ob->set("max_qi",me->query("max_qi")* 3 / 4);
		ob->set("eff_qi",me->query("max_qi")* 3 / 4);
		ob->set("qi",me->query("max_qi")* 3 / 4);
		ob->set("max_jing",me->query("max_jing")* 3 / 4);
		ob->set("eff_jing",me->query("max_jing")* 3 / 4);
		ob->set("jing",me->query("max_jing")* 3 / 4);

	level = (int)me->query_skill("force",1) * 5 / 6;
  if (level <=50) level=50;
  if (!level) level=50;
if (level <=50) level=50;
  if (!level) level=50;
		ob->set_skill("feitian-yujianliu", level); 
		ob->set_skill("force", level);
		ob->set_skill("unarmed", level);
		ob->set_skill("xuanhualiu-quanfa",level);
		ob->set_skill("dodge", level); 
                ob->set_skill("blade", level); 
		ob->set_skill("aikido", level); 
		ob->set_skill("wuxing-dun", level); 
		ob->set_skill("shayi-xinfa", level);
		ob->set_skill("parry", level); 
		ob->set_skill("literate", level); 
		ob->set_skill("feitian-yujianliu", level); 
                        ob->map_skill("parry", "aikido");
                        ob->map_skill("unarmed", "aikido");
                        ob->map_skill("dodge", "wuxing-dun");
                        ob->map_skill("force", "shayi-xinfa");
                        ob->map_skill("blade", "feitian-yujianliu");

		ob->move(environment(me));
		ob->kill_ob(me);
		me->kill_ob(ob);
		me->start_busy(1);
call_out("rfeitian", 60 , me,obj );
}
else    call_out("rfeitian", 20 , me,obj );
    return 1 ;
}

void rfeitian( object me,object obj )
{
    if (!me || me->is_ghost()) return;
  tell_object(me , "����������ô�����ڵִ���һ�������˶���Ȫ�ޡ�\n" ) ;
  me->move ("/d/quanzhou/haigang.c") ;
if (obj) obj->move("/d/quanzhou/haigang");     
}


int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;
if (level <=30) level=30;
	return level;
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
if (dir=="south")
{
		if ( me->query("family/family_name") != "����������" && dir !="north")
		return notify_fail("ֻ�з��������������˲���ʹ�ÿ촬����������\n");
}	


	return ::valid_leave(me, dir);
}
