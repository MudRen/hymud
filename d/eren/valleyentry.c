 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ɽ��");
        set("long", @LONG
Ⱥɽ����Զ���������ڽ������¼ŵ�ɽ�ȣ����˵ĵ��ϣ���¶���˼�����
��Ϣ��ɽ·������᫣���ʯ���м���Ұ����ǿ�����ͷ����һյ����ƳɵĿ����ƣ�
�����Ƕ��ɽʯ��ܷ紦�������׵Ŀ���������һ�㣬ϸ����ɽʯ�Ͼ���������
�֣��������죬��������ߡ�
LONG
);
        set("exits", ([ 
        //"northdown" : __DIR__"road3",
        "westup" : __DIR__"road2a",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1250);
        set("coor/y",2040);
        set("coor/z",30);
        setup();
}  
void init ()
{ 
   add_action("do_look", "look");
   add_action("do_northdown", "northdown");
} 
int do_northdown(string arg)
{
        object me, room;
        me = this_player(); 
        if(me->query_temp("marks/look")) {
                tell_object(me, "������С·����������ȥ��\n\n");
        message("vision", me->name(me)+"�������ѵ�ɽ·ת�˼�ת��ʧȥ����Ӱ��\n", environment(me),me );
        room = find_object(__DIR__"road3");
        if(!objectp(room)) room=load_object(__DIR__"road3");
        me->move(room);
        me->delete_temp("marks/look");
           return 1;
        }
   return 0;
} 
int do_look(string arg)
{
   object me, room;
   me = this_player();
   
   if (arg!="rock" && arg!="ɽʯ" && arg!="stone" )
        return 0; 
   tell_object(me,"�������£���ֻ��ͷ��ָ�����������ѵ�ɽ·���þ�Ŀ��������Ƴ�����·����ͨ
��������ɽ�ϱ���ɽ�ȡ�\n");
   message("vision",me->name(me)+"��ϸ�ؿ���ɽʯ�ϵ��֡�\n", environment(me),me);
   me->set_temp("marks/look", 1);       
   return 1;
}  
