//1997-3-10 by qyz
#include <room.h>
#include <ansi.h>

inherit ROOM;


void create()
{
	set("short",WHT"���׶�"NOR);
	set("long",@LONG
���׶��ֽ��ɺ׶������ھ���֮�ϣ���˵���������ף����ǹ������ǰ����
ͯ��ֻ�����������Ŷ���ȡ��Һ��ˮ����������Ů����������Ӵ�ŭ������ͯ��
Ϊ���״���ʯ�����Ӵˣ����������࣬�����ƣ��ݾӲ�����ż���������ͷ�֮��
���������衣�ִ�˵���׳���������Ӿ�Ҫ�����ɽ��ͽ��
LONG);
	set("exits",
	([
          "southdown" : __DIR__"xiangtou_ya",
          	]));
        set("outdoors","kongdong");
	set("objects",([
	__DIR__"npc/meihua_lu" : 2,
		]) );
        setup();
        //place_program(ROOM);
}
void init()
{
    object me;
    me = this_player();
    if (!wizardp(me)&&userp(me)&&!me->query("marks/kongdong/zhou"))
    {
        message_vision("����ô������.....��ȥ��.....\n",me);
        me->die();
    }
    add_action("do_perform","perform");
    add_action("do_search","search");    
}

int do_search()
{
	object me=this_player();
//	if (me->query("marks/kongdong/dao"))
	{
	tell_object(me,HIG"�������������ģ����ɵ��Ĵ���̽��һ�����������۹����ڶ���һ��ͻ������ʯ�ϡ�\n"NOR);
	tell_object(me,HIG"�β��������ʯ���������ɵĺ��ҵ�����\n"NOR);
	me->set("marks/kongdong/dao",2);
        return 1;              
	}
	return 0;

}

int do_perform()
{
	object me=this_player();
	object ob;
  	ob = me->query_temp("weapon");
 	if ( !ob || (string)ob->query("weapon_type") != "blade" )
	{tell_object(me,"��ϧ��û�д�����\n");
	return 1;} 	
	if (me->query("marks/kongdong/dao")!=2)
	return 0;
	if (me->query_jibie("hujia-dao")<135)
	{tell_object(me,"��ĺ��ҵ�����Ϊ�������ڴ˴�ʩչ����������\n");
	return 1;}
	if (this_object()->query_temp("performed"))
        {message_vision("��ʯ�Ѿ��������ˡ�\n",me);
        return 1;
	}        
	message_vision(HIB"$N��׼�ǿ�ͻ������ʯ,����һ����ʹ������˷��ľ�����������ʯѸ����\n����ʵ����˵������еĵ���ͬ���\nɲ�Ǽ䣬���쵶��Ӹ�������������ʯ��\n"NOR,me);
	if (me->query("force_factor")>450)
        message_vision(HIR"һ����ʯײ��֮�����󣬾�ʯ����Ӧ�����ѣ���Ȼ¶��һ��⻬��ʯ������\n",me);
        this_object()->set_temp("performed",1);
        new(__DIR__"obj/shibi")->move(this_object());       
        return 1;
}


int valid_leave(object me,string dir)
{
    if(dir=="southdown")
      message_vision("$NС����������Ҹ��ݣ���ɽ����ȥ��\n",me);
    return ::valid_leave(me,dir);
}
