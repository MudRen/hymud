 inherit ROOM;
void create()
{
        set("short", "˽��ѧ��");
        set("long", @LONG
������ǰ��һ��ϴ�µ꣬����Ǯ�˽��·�������ϴ�ĵط����Դ�������ϰ���
ȥ�����Ժ���һ������ס�˽����������ĳ�һ��˽�ӣ�����Ϊ����̫�ң���û��
����ѧ�����ſ���һ����ľ�ƣ�������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ecloud3",
])); 
        set("item_desc", ([
                "sign": @TEXT
��˽�����������ĸ�����+,-,*,/,��()�����ʮ�ġ�
���磺 
������ĸ����ǣ���,��,��,��. ����һ�����ڸ�����(answer)
answer (9-2)*3+3
��һ����ԵĽ���һ���ġ�
TEXT
        ]) );
        set("objects", ([
        __DIR__"npc/taipo" : 1,
                        ]) );
        set("coor/x",30);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
