//Cracked by Roath
// Room: /d/xiyou/nanhai/shuyuan
inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

�����������ɽ��Ժ������ϰ��������鼮������ɽ���˵���
��������߻�������ʶ�ֵģ�������������з������𷨵ģ�
���������޵�������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang",
]));
  set("objects", ([ /* sizeof() == 3 */

  __DIR__"npc/shami" : 1,
]));
  set("light_up", 1);

  setup();
}
