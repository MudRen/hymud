#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
һ���ƾɵ�ʯ�ݣ���ȷ�е�˵ֻ�Ǹ�ʯ�����ƺ�������������ʳ������ģ���
���Ĺ����ҵ������װ���˹��ӣ�һ�����ң��������������ڽ������������
��û�������������еĶ����϶�����һ��ҡ�
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"yongdao7",    
                "east" : __DIR__"yard2",        
        ]));
        set("objects", ([
                __DIR__"obj/pumpkin" : 2,
        ]) );
        set("item_desc", ([
                "���": "һ��������ĵ��״�������װ���˹��ӡ�\n",
                "���": "����ϻ��˺���һ��ҡ�\n",
                "bag": "һ��������ĵ��״�������װ���˹��ӡ�\n",
                "����": "����ͨ��ũ���þߣ�����ǽ�ϡ�\n",
                "basket": "����ϻ��˺���һ��ҡ�\n",
                "dingba": "����ͨ��ũ���þߣ�����ǽ�ϡ�\n",
                "��":"����һ��ң�Ҳ�����������Ĩȥ(remove)����\n",
                "dust":"����һ��ң�Ҳ�����������Ĩȥ(remove)����\n",
                "hui":"����һ��ң�Ҳ�����������Ĩȥ(remove)����\n",
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
void init(){
        add_action("do_remove", "remove");
} 
int do_remove(string arg){
        object me, guard;    
        me = this_player();
        if(!arg || (arg != "dust" && arg != "��")) {
                return 0;
        }
        message_vision("$N������Ĩȥ���ϵĳ�����\n",me);
        message_vision("����¶�������϶�������Ѫ�֣�"+HIR"Σ�ա������ء����ơ���\n"NOR,me);
        return 1;
}
