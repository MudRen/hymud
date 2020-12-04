#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "Сʯ��");
        set("long",  @LONG
ʯ����һ�鰼���ĵط���Լ����һ�ɸߣ����ɼ���������һյ�͵ƣ����ż���
ľ���һ�Ŵ������Ϻ��Ҷ��ż�������������Щû�����ʳ��ı�������ʪ����
������̦��
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao3",
        ]));
        set("objects", ([
                __DIR__"npc/guarda" : 2,
                __DIR__"npc/guarda1" : 1,
                
        ]) );
        set("item_desc", ([
        "��̦" : "��ɫ����̦�����˶��ڡ�\n",
        "moss" : "��ɫ����̦�����˶��ڡ�\n",
        "�͵�" : "һյ�͵ƣ��ƺ�û��ʲô�ر�ĵط���\n",
        "lamp" : "һյ�͵ƣ��ƺ�û��ʲô�ر�ĵط���\n",
        "ľ��" : "����ľ�������������һ����ʱ�����ӡ�\n",
        "box" : "����ľ�������������һ����ʱ�����ӡ�\n",
        "��" : "һ�Ŷ���һ���ȵ�ľ������������ֵ��Ϣʱ�õġ���ϸ��ȥ����ͷ�ƺ��и���ť��push����\n",
        "bed" : "һ�Ŷ���һ���ȵ�ľ������������ֵ��Ϣʱ�õġ���ϸ��ȥ����ͷ�ƺ��и���ť��push����\n",
    ])); 
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        set("trap",1);
        setup();
        
} 
void init(){
        add_action("do_push", "push");
} 
int do_push(string arg){
        object me, guard;    
        me = this_player();
        if(!arg || (arg != "button" && arg != "��ť")) {
                return 0;
        }
        if (guard=present("lieutenant",this_object()))
                return notify_fail("СͷĿ���һ������͵͵���������ʲô����\n");
        if (guard=present("guardian",this_object()))
                return notify_fail(guard->query("name")+"���һ������͵͵���������ʲô����\n");
        if(query("trap")) {
                tell_object(me,HIW"��С���������������ť�����ں���һ�����ǵ������������־���������\n"NOR);
                this_object()->set("trap",0);
        } else {
                tell_object(me,HIW"��С���������������ť��ʲô����Ҳû�С�\n"NOR);
                }
        return 1;
} 
void reset()
{
        ::reset();
        set("trap",1);
        
}       
