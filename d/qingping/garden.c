 inherit ROOM;
#include <command.h>
#include <ansi.h> 
void create()
{
        set("short", "��԰");
        set("long", @LONG
��������ƽɽׯ�ĺ�԰����԰���󣬿��Ǵ�ʱ�����ٻ�ʢ��֮�ʣ�԰��һƬ
�������������档����Ժǽ������һ���ϻ�������ʹ�������ȵ��ļ���������Ҳ��
��ˬˬ�������ʱ���ϻ������ǿ�����һ������׵Ļ��䣬΢����������˵Ļ�
���Ʈ����������ƽɽׯ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"studyroom",
  "south" : __DIR__"xting",
  "east" : __DIR__"pond",
  "west" : __DIR__"neiyuan",
   ])); 
   set("item_desc", ([
      "tree" : "Ũ�ܵ��ϻ���������Ժǽ��һֻ�ִֵ�֦�����쵽��ǽ�⡣\n",
      "�ϻ���" : "Ũ�ܵ��ϻ���������Ժǽ��һֻ�ִֵ�֦�����쵽��ǽ�⡣\n",
   ]) ); 
   set("objects", ([
      __DIR__"npc/yan" : 1,
   ]) );
        set("outdoors","qingping");
        set("coor/x",170);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
} 
void init()
{
   add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
   object me, room;
   int mlvl;
   
   me = this_player();
   if(!arg || arg != "�ϻ���" && arg != "tree") return 0; 
   mlvl = (int)me->query_skill("move");
   if(mlvl < 50)
      message_vision("$N�������ϻ���������ûϣ������ȥ��\n", me);
   else{
      message_vision("$N���ֽý����������ϻ�����\n", me);
      room = find_object(__DIR__"midtree");
      if(!objectp(room)) room=load_object(__DIR__"midtree");
      me->move(room);
   }
   return 1;
} 
void kite_notify(object obj, int i)
{
   object  me, room;
   int j;
        
   me = this_player();
   message_vision("һ��΢�����"+obj->name()+"����������������\n\n" , me);
   message_vision("ͻȻһ�󾢷磬"+me->name()+"���е��߶��ˣ�"+obj->name()+"�λ����Ƶ�Խ��Խ�ߣ����������ˡ� \n",me);
   destruct(obj);
   return; 
}  
