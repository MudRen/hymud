 inherit __DIR__"no_killing_place";
void create()
{
    set("short", "С�Ӷ���");
    set("long", @LONG
���ܵĲ�ƺ�޼��ú����룬���źӰ�������һЩˮ��ֲ��и�Ƽ��ˮ�ɣ���
�м���«έ����Զ���Ĳ�ƺ�ϴ������µذ���һЩ΢��̨ͤ¥����ɽʯ��ľ����
��ȥ����һ����ǽ���ߵ�СͥԺ����������ӷ�ǽ��̽��ͷ�����ҡ�������ܾ���
�ĵģ�ż�����������������Ĺ�������
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"bridge",
        ]));
 
        set ("no_magic", 1);
    set("outdoors","taoyuan");
    set("coor/x",260);
    set("coor/y",-40);
    set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}  
