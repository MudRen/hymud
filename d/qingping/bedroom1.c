 //XXDER@fy3
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���䲻��Ҳû��ʲô���裬ֻ��ǽ�ϳ�������עĿ��ס���������
Ī��������η�����ﲻ�ǣ���������й��ﲻ�Ǵ����������Ǽ�����
��˫���������³��ѣ������������һʱ֮ѡ���������䲻��ȴҲ��?
�����˲��õľ���������
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road2",
])); 
   set("objects", ([
      __DIR__"npc/jin": 1,
   ]) );
        set("coor/x",150);
        set("coor/y",2010);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
