// Room: /d/taiwan/chitang
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
�ƿ�ҡ�εĴ���,��Ծ��ķ�����ǰ��Ȼ�Ǹ�����,���е����˲�֦
��Ҷ,���л��к�ɫ�������ι�.�������滹��һ��С����,ͨ������.
LONG);

  set("outdoors", "/d/taiwan");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"huilang",
  "south" : __DIR__"zhuanyuan",
]));
  setup();
}
void init()
{
   add_action("do_jump","jump");
}
int do_jump(string str)
{
   object ob;
   ob=this_player();
   if (!ob||environment(ob)!=this_object()) return notify_fail("");
   message_vision("$N��ͨһ�������������ĳ���!\n",ob);
   ob->move(__DIR__"tangzhong");
   return 1;
}