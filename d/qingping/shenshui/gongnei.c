 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ˮ��");
        set("long", @LONG
�����ˮ������䣬ͻȻ���������ǰһ������ͷð��ˮ�棬�����Լ�
����һ����ˮ���ԭ�������ˮ�����������ŵģ���ˮ��������ƽ��ֻ��
ˮ�ص�����������������䣬�Ե�ʮ�ָ����ûʡ�
LONG
        );
   set("exits", ([ 
      "up" : __DIR__"rongdong",
   ]));
        set("coor/x",210);
        set("coor/y",12300);
        set("coor/z",0);
        setup();
} 
void init()
{
   add_action("do_dive", "dive");
} 
int do_dive()
{
   object me, room;
   me = this_player(); 
  message_vision("$N����һ������һ������������ȥ��\n\n", me);
  room = find_object(__DIR__"gongmen");
  if(!objectp(room))  room = load_object(__DIR__"gongmen");
  me->move(room);
  message("vision", me->name()+"�Ӷ������˳�����\n", environment(me), me);
  return 1;
}      
