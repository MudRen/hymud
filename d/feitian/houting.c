// Room: /d/feitian/houting
inherit ROOM;

void create()
{
  set ("short", "��ͥ");
  set ("long", @LONG
���ǵ����ĺ�ͥ������Ժ���з����ż���ľ�ˡ������������������书�õ�
��Ҳ������ȥѵ��һ�¡���Զ������ԼԼ���ĵ�һ��С���ӡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"chucangshi",
  "south" : __DIR__"daochang",
]));
  set("outdoors", "feitian");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/muren" : 4,
]));

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dizi" : 2,
]));
  setup();
  replace_program(ROOM);
}
