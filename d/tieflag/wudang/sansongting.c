 inherit ROOM;
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
����������ɣ���ֲ�ͱڣ��������У��֦��չ������ͦ�Σ���
�����롣��ʫ�ƣ����Ʋ��������Σ��Կ���֦ɨ���������ð������
���ͱ�֮�ϳ�������γ�һ����Ȼ���ϡ�֦Ҷ�ڰ�վ��ύ������
��һ����ɡ���ַ���һ���������ֳ�����ͤ��
LONG
        );
        set("exits", ([
                "east" : __DIR__"jianquan",
                "northdown" : __DIR__"wall",
        "southup" : __DIR__"fourgate",
        ]));
        set("objects", ([
                __DIR__"obj/tree" : 1,
       ]) );
        set("outdoors", "wudangfy");
        set("coor/x",110);
        set("coor/y",-170);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
}  
