#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
        set("short", "����");
        set("long", @LONG
��������ߺܺã�����������һ�źܴ�İ��壬��������ʰ�÷ǳ��ɾ�������
����һ�������ߴ�ɵ���̨����̨�µ���˻����Ű���ɫ����̨�Ϸ���һ��������
��������Ʈ����Ũ���Ĵ���͵����Ĵ��̡�
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"cyard",
        ]) ); 
        set("objects", ([
                __DIR__"obj/oven" : 1,
                __DIR__"obj/pot" : 1,
        ]) ); 
        set("no_magic", 1);
    set("coor/x",220);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
}
void reset()
{
        object          *inv;
        object          con, item;
        int             i; 
        ::reset();
        con = present("pot", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
        }
        con = present("oven", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/scallion");
                item->move(con);
                item = new(__DIR__"obj/caidao");
                item->move(con);
                item = new(__DIR__"obj/lighter");
                item->move(con);
                item = new(__DIR__"obj/candle");
                item->move(con);
        }
} 
void burn_notify(object ob) {
        object me;
        
        me = this_player();
        if(me->is_fighting()|| me->is_busy()) {
                return notify_fail("������æ��\n");
        }
        message_vision(RED"$N����ʯ������̨�µĻ��Ϻ濾��\n"NOR, me);
//      if(me->query("����B/��ɽ_�ٲ�") && !me->query("stone_mark/ystone")) {  
        if(!me->query("stone_mark/ystone")) {  
                message_vision(HIY"\nʯƬ�������һ�����䡣¶��һ�龧Ө���εĻ�ʯ��\n"NOR, me);
                destruct(ob);
                if(!me->query("m_success/��¶��ʯ")){
                        me->set("m_success/��¶��ʯ",1);
                        me->add("score",1000);
                }
                me->set("stone_mark/ystone", 1);
                ob = new("/obj/specials/stone/ystone");
                ob->move(me);
        } else {
                tell_object(me, "\nʯ�鱻���ù��̡�\n");
        }
}      
