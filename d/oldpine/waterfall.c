 // Room: /d/oldpine/waterfall.c
inherit ROOM; 
void create()
{
        set("short", "�ٲ�ǰ");
        set("long", @LONG
��������վ���ٲ�ǰ��һ��Сˮ̶�ˮ̶��Լ��ɼ��أ��Ͳ���
�ˣ�һ����������ٲ��������ɸߵ������ϳ弤���£�������ȫ��ʪ͸��
ˮ̶���涼�����ʵ�ɽ������Χ��ֻ����������һ��ɽ�����Գ�ȥ��
LONG
        );
        set("item_desc", ([
                "waterfall":
                        "����ٲ�ˮ�Ʋ����Ǻܴ󣬵��Ǹ߶�ȴ���ߣ�ˮ�齦���������\n"
                        "����������ۡ���ע�⵽�ٲ������ƺ���ʲ�ᶫ���ڷ����⡣\n",
                "cliff":
                        "ˮ̶���ܵ�ɽ�ڶ��������ɸߣ���Ҫ����ȥ���϶��������롣\n"
        ]) );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"riverbank2",
]));
        set("resource/water", 1);
        set("coor/x",540);
        set("coor/y",2360);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}       
