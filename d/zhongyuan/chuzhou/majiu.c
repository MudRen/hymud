// ���������ھ� /d/city/chuzhou/biaoju.c

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", YEL"�����ھ�"NOR);
    set("long", @LONG
���ݵ������ھ�˵���ھ֣���ʵ����˵�Ǽ���ݸ����ʣ���Ϊ�ھֵ�������
ͷ�����ݵȵص�ͬ�еľ����£��ܾö�û�нӵ�����ˮ�Ƚϴ�����ˡ�û�а취��
�������Σ�������ͷֻ�ÿ������������Ϊ���˼ķ���ƥ������������ά���ھ�
�ˡ��ſ���һ��������д��Щ�����ھֵĹ�ء�
LONG
    );
    set("no_kill",  "yangzhou");
    set("outdoors", "chuzhou" );
    set("detail", ([
        "����"  : "����������һ�Σ�����������\n�ķ���ƥһƥ����Ǯ����ġ�\n",
        "paizi" : "����������һ�Σ�����������\n�ķ���ƥһƥ����Ǯ����ġ�\n",
        "sign"  : "����������һ�Σ�����������\n�ķ���ƥһƥ����Ǯ����ġ�\n",
    ]));        
    set("exits", ([
        "west"  : __DIR__"wuhua_jie",
//        "east"  : __DIR__"majiu",
        ]));
    set("objects", ([
        __DIR__"npc/biaojuboss" :   1,
//        __DIR__"npc/daughter"   :   1,
    ]));        
    setup();
}
