 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "������");
        set("long", @LONG
���������������£��޴��ɽӰ�����ص�ѹ�ڹ����ĳ����ϡ����ں��ţ�ȴҲ
����������ɭ���Ե�����ɽ´��Ӱ�У��м�����������ЪϢ��������һ�������
�����ͨ��߳ǡ�������ͨ�������嶥��ɽ·����᫶��������ϡ�
LONG
        );
        set("exits", ([ 
                "southeast" : __DIR__"kunlun3",
                "southwest" : "/d/biancheng/wild1",
                //��������ʦ̫
                "northup" : __DIR__"road0",
                "west":         "/d/zangbei/wild1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1020);
        set("coor/y",150);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
/*int valid_leave(object who, string dir) {
        if (dir=="west") {
                if (!wizardp(who) && !who->query("beta_test"))
                        return notify_fail("��ɳ�ն����е�·��ʱ�رա�\n");
        }
        return 1;
} */ 