#include <ansi.h>
inherit ROOM; 
int blinding(object me);
int bbqthem(object me, object obj); 
void create()
{
        set("short", "�ӻ��ַ̲�");
        set("long", @LONG
̫ƽ�ӻ���ʵ���Ǹ����׼׼�������̣�ˢǽ�İ׷ۣ���ɫ������ͩ�ͺ��ᣬ
���ǣ����������ף�С�ף�������Ѽ�������ۣ����ߣ�Ь�ӣ���ƥ�����̣��Ͼơ���
ֻҪ������õ��Ķ��������ﶼ�У������벻���Ķ������ﶼ�С�һ��ô�ô��
������������廨���ţ���ʽ�����Ķ�������������һ������������ĵ�ǹ����
һ�����װ�ľɻ���
LONG
        );
        set("exits", ([ 
                "east":  __DIR__"mroad3",
                "west": __DIR__"zahuo2",
        ]));
        set("item_desc", ([
        
         ]));
         set("objects", ([
                __DIR__"npc/oldworm" : 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
             
