inherit ROOM;
void create()
{
        set("short", "�ؽ�");
        set("long", @LONG
�ؽ��ﺮ�����ʪ��������ǽ���Ϲ���һյ�͵ơ��谵�ĵƹ��£�
������Ե���ɭ�ɲ���
LONG
        );
        set("exits", ([
                "up" : __DIR__"dijiao",
        ]));
        set("no_magic",1);
        set("coor/x",-1120);
        set("coor/y",-120);
        set("coor/z",-30);
        setup();
        replace_program(ROOM); 
}      
