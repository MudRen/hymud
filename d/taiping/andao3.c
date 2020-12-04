#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�ص��ľ�ͷ��һ��ʯ�š����Ե�ǽ���ϸ�����һյ�����ơ����������Ͱ�����
���ϵƴ�ſ���ά�������ա��ƹ�����������ʯ�š���ʯʯ�����������ֵĻ��ƣ�
��Щ����������¥���������Ǽ�ħ���Ż��Ͽ��ŵľ���Щ���ơ�����ɫ�Ļ��ƣ���
���У���ҫ�������ĺ�â������������ģ�ȴ�ƺ���ʲô���������⡣
LONG
        );
        set("exits", ([ 
                "westup":  __DIR__"andao2",
//              "south":  __DIR__"stoneroom",
        ]));
        set("item_desc", ([
                "����": "��ϸ���ϣ�ʯ����д������������֣�--�����⡱��\n",
                "ʯ��": "��ϸ���ϣ�ʯ����д������������֣�--�����⡱��\n",
                "door": "��ϸ���ϣ�ʯ����д������������֣�--�����⡱��\n",
                "����": "�ص��Ķ��ھ�Ȼ�м��ŷ��������ڵķ����к�â��˸��һ��һ�еľ��Ƿ�����ǹ�⡣
ǧ��֧��ǹһ�����£��ص��е����߱ܲ�����ɴ�⬡��������ź�ÿ��ٺ��ˣ���
�ܶ��������ء�\n",
                "roof": "�ص��Ķ��ھ�Ȼ�м��ŷ��������ڵķ����к�â��˸��һ��һ�еľ��Ƿ�����ǹ�⡣
ǧ��֧��ǹһ�����£��ص��е����߱ܲ�����ɴ�⬡��������ź�ÿ��ٺ��ˣ���
�ܶ��������ء�\n",
         ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_push", "push");
}  
void close_passage()
{
        object room;
        message("vision", "ʯ��������Ϣ����ת�˻�������ס�˰�����\n", this_object() );
        set("door_opening",0);
        delete("exits/south");
} 
int do_push(string arg)
{
        object obj, room, me;
        me=this_player();
        if(!arg || (arg != "ʯ��" && arg != "��" && arg !="door")) {
                return 0;
        }
        if (query("exits/south"))
                return notify_fail("ʯ���Ѿ����ˡ�\n");
        if (me->query_str()<=60)
                return notify_fail("��һ����ȥ��ʯ����˿������\n");
        if (query("door_opening"))
                return notify_fail("ʯ���Ѿ����ƶ��ˡ�\n");
        
        message_vision(WHT"$N˫����סʯ�ţ��Ϳ�����һ��������һ�����������ϣ���\n"NOR,me);
        message_vision(WHT"�����������أ�ʯ�ſ�ʼ�����ƶ���������\n"NOR,me);
        set("door_opening",1);
        call_out("arrow_trap", 6);
        return 1;
}  
void open_passage() {
        message("vision","֨֨�¸�һ���춯��ʯ�����ڴ��ˡ�\n",this_object());
        set("exits/south",__DIR__"stoneroom");  
        call_out("close_passage", 20);
} 
void arrow_trap() {
        object *inv;
        int i;
        message("vision",HIR"\n��Ȼ��������л���֮�������������Ͼ�Ȼ�������ʮ֧��ǹ��\n\n"NOR,this_object());
        inv=all_inventory(this_object());
        for (i=0;i<sizeof(inv);i++) {
                if (!inv[i]->is_character()|| inv[i]->is_corpse()) continue;
                message_vision(WHT"$N��ܲ���������ǹ���˸�͸����������\n"NOR,inv[i]);
                inv[i]->receive_wound("qi",10000);
        }
        call_out("open_passage", 4);
} 
void reset()
{
        ::reset();
        delete("exits/south");
        set("door_opening",0);
}  
