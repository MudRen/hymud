 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ִ�Ӱ��ֱ�����������ı���Ϊ��ɮ�������������ĵ�����
ɮ��Ԫ׫�ġ�Ϣ����ʦ����֮�������漪������Ȼ�鵤����������
ɮϢ�ֵ���ƽ��ѧ��֮�˵���Ч��Ϣ����Ϊ�����ܳ�һ����ʦ��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bei1",
  "southeast" : __DIR__"yingbi",
]));
        set("objects", ([
                __DIR__"obj/bei2" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-220);
        set("coor/y",180);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}      
