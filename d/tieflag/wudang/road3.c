 inherit ROOM;
void create()
{
        set("short", "��ɽ·");
        set("long", @LONG
��������������·��ȴ��ƽ̹���������߶���ïʢ�����֣����
����ʱ�������������������ķҷ�����һ����ʹ�����ؿ��ʣ�����
һ�з��ա�����������ֵķ�϶��ɼ�������۵ĺ�ɫΧǽ��
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"rock",
                "southup" : __DIR__"wudang",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-120);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}  
