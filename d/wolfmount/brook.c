#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "佻�Ϫ"); 
        set("long", @LONG
һ���峺���׵�Ȫˮ��ɽ�н����������������д��ӵ��أ�����С���������
�̣�����ɽ��������Ϫˮ�и�ɫ�ͷ׵Ļ�������Ϫˮ���������ʣ�һ�������续��
Ȫˮǳǳ���У��������ϣ��ɿ�����Զ���������ȪˮԴͷ�и�������
LONG); 
        set("type","waterbody");
        set("outdoors", "wolfmount");
        set("exits",([
                "southeast":__DIR__"brook4",
                "southwest":__DIR__"brook3",
        ]) );
        set("objects",([
                __DIR__"npc/xiaoling":1,
                __DIR__"npc/xiaorou":1,
        ]) ); 
    set("coor/x",-720);
    set("coor/y",-710);
    set("coor/z",60);
        setup();
} 
void init()
{
        add_action("do_look", "look");
} 
void conch_notify()
{
        object me;
        int lel;
        me = this_player();
        lel = me->query("kar");
        if(random(100) < lel) 
        {
                remove_call_out("fog_disappear");
                call_out("fog_disappear",3,me);
        }
   else 
        {
                message_vision("�����ã��������ɣ�ʲô��û�з�����\n",me);
        }
        return;
} 
int valid_leave(object me, string dir)
{
	if ( objectp(present("xiaorou", environment(me))) && 
		dir == "southwest")
		return notify_fail("��С����ס�����ȥ·��\n");

	if ( objectp(present("xiaoling", environment(me))) && 
		dir == "southwest")
		return notify_fail("��С����ס�����ȥ·��\n");


me->set_temp("marks/wolf_blow_conch",1);
	return ::valid_leave(me, dir);
} 

int do_look(string arg)
{
        object  me;
        me = this_player();
        if( arg == "southwest") 
        {
                message_vision(HIY"$N̽ͷ̽�Ե������Ϸ����˿�������������\n"NOR, me);
                tell_object(me,"�Ǳ�����������ʲô����������\n"); 
                return 1;
        }
        return 0;
}  
