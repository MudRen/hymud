inherit ROOM;

void create()
{
        set("short", "��̲��");
        set("long", @LONG
����ĺ�ˮ�ǳ�ƽ�������Ŀ������������Ƭ��̲λ��һ��
�����б�������ʯ�º��棬��ʯ��û���ڵ�һ�����Լ����
ʮ��СС��ɺ�����������һ�ɶ�ߣ�����ӿ�ĺ��˾�֮���⣬
ʹ�����Ϊһ����Ȼ�ıܷ��
LONG
);
        set("exits", ([ /* sizeof() == 3 */
        "northwest" : __DIR__"jhd28",
]));

        set("outdoors", "jinghai");

        setup();
}
