 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
ת�˼����䣬�붴�����ǰ���ֲ�����ָ����Χ��ʱ����С������
����ɳɳ����������η�������ͷȴ�Ѳ�֪��ʱ�ĵ�·����������Ҳ�ֲ�
�嶫���ϱ���ֻ�ô����ŷ���׳�ŵ�����������ǰ�ߡ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"midao2",
  "north" : __DIR__"midao7",
]));
        set("coor/x",100);
        set("coor/y",12070);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
