inherit ROOM;

void create()
{
      set("short", "��ʯ��");
      set("long", @LONG
������һ��������ͷ׵�ʯ���̳ɵ�С·�ϣ�ʯ������˸�
�ֻ��ơ�С·�������������ӣ�����ɭɭ���������ء���ʱ��ݺ
���������������������Ŀ������������Ҫ�쵽�������ˣ�����
����������¥������
LONG
      );
      set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"wm20",
  "east" : __DIR__"wm3",
  "west" : __DIR__"wm9",
]));
        set("outdoors","jinghai");

   setup();
  replace_program(ROOM);
}
