 inherit ROOM;
void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
������Ҷ֮�䣬һ����Ȫ����ɽ���������������겻�ϡ���˵
�У���ͥ���佫�������ѱ����������˼䡣��������ɽ�ϣ����ǽ���
�Ľ�Ȫ����ȪȪˮ����������·�˽�ͣפ�ڴˡ���ϢƬ�̣�������ɽ��
����Ȫˮ���ˣ�����������������У�����������·��
LONG
        );
        set("exits", ([
                "west" : __DIR__"sansongting",
        ]));
        set("outdoors", "wudangfy");
        set("resource/water",1);
        set("liquid/name","��Ȫˮ");
        set("liquid/type", "water");
         set("objects", ([
                __DIR__"obj/pestle" : 1,
       ]) );
        set("coor/x",120);
        set("coor/y",-170);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
}  
