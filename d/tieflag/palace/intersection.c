 inherit ROOM;
void create()
{
        set("short", "��·��");
        set("long", @LONG
·����������ǰ�ͷֳ�����������һ������������ɫ�ľ�ʯ������
ƽ̹��Ŀ��·����ֲ���л��ݣ��޼����룬����Ϯ�ˡ����ҵ�һ����ʯ
��·��ȴ���۵�ͨ��һ����ɭ��Ĵ��֣���·��᫿�����������紵
��������ʪ�ĳ�����
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"white",
  "south" : __DIR__"black",
  "west" : __DIR__"bridge",
]));
        set("outdoors", "palace"); 
        set("coor/x",160);
        set("coor/y",10);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",10);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",10);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",10);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}  
