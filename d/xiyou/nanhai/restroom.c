//Cracked by Roath
// Room: /d/xiyou/nanhai/restroom
inherit ROOM;


void create ()
{
  set ("short", "��Ϣ��");
  set ("long", @LONG

����������ɽ����Ϣ�ң�������յ�����ʲôҲû�У���֪����
ɽ���˵���������ô��˯���ġ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang2",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);
  set("sleep_room", 1);

  setup();
}
