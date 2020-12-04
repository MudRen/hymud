// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit ROOM;

#define BUSY        1     // �����BUSY      
#define TRIP        2     // �����ˤ����ķ���   
#define LOSTMAP     3     // ���Թ���ͼʧЧ       
#define CHANGEMAP   4     // ���Թ���ͼˢ��       
#define WOUND       5     // ���������          

void create()
{
        set("short", "�Թ�");
        set("long", @LONG
����һ�����ʯ�ݣ����ܾ�ʯ�ݾ͵�ǽ�ڷ������ĵ���ɫ��â����յ��ͭ
���³�һ�߸ߵĻ��棬Ʈ����˸��żȻ�еƻ����ѵ����죬�����˸е���Ϣ���
�ž��������������������ʯ���̾ͣ���������һ���ɫʯ�������Ŀ�������
����ϸ�ܵ�ͼ�ƣ����˲�������������ǰ�鿴��mazemap��һ����
LONG );
        setup();
}
    object get_object(string name) 
    { 
            object ob; 
            
            if (ob = find_object(name)) 
                    return ob; 
                     
           sscanf(name, "%s#%*s", name);  
            return load_object(name); 
     } 
void init()
{
        object me, room, next_room;
        int trap;
        object mazeobj;
        int damage;

        room = this_object();  
        if( !(me = this_player()) ) return;
        if( !(trap = room->query("maze/trap")) ) return;
        mazeobj = get_object(room->query("mazeobj"));
        if( !mazeobj) return;    
        switch( trap ) {
        case BUSY:
                message_vision(HIR "\n$N����һ�������ˤ������࣬�ò�������ס��"
                        "�ӣ��Ÿо�����Ť���ˣ���ʹ��...\n\n" NOR, me);
                me->start_busy(5);
                break;
        case TRIP:
                message_vision(HIR "\n$Nһ�Ų�����ʲô������������Ҳ�ѳֲ�ס����"
                        "����ǰ������ֻ����һ�����оþûص�...\n\n" NOR, me);
                next_room = mazeobj->trip_maze(room);
                if( objectp(next_room) )
                        me->move(next_room);
                break;
        case LOSTMAP:
                message_vision(HIR "\n$Nֻ���ý���һ���������죬���������������"
                        "��ɫʯ������һ��ǿ�⣬����Ѹ��������ȥ...\n\n" NOR, me);
                // mazeobj->set_display_map(0);
                break;
        case CHANGEMAP:
                me->start_busy(3);
                mazeobj->init_maze(room);
                message_vision(HIR "\n$Nһ�Ųȵ���ʲô���������̵̻İѽ�����ȴ"
                        "�Ѿ�����������Ƶ������ӵ�������...\n" NOR 
                        HIR "ֻ�����ܹ�Ӱ�ζ������������ƺ��ڿ����ƶ�����һ�а���"
                        "���������⾰���ƺ������ı䡣\n\n" NOR, me);
                
                break;
        case WOUND:
                message_vision(HIR "\nֻ����һ���������죬$N����ʶ�ĸϽ����ã�ȴ"
                        "Ϊʱ����һ֧����ƫ������������$N��\n" NOR 
                        HIR "$N��ŭ���ӣ��˿ڴ�ʹ�����飬�����̲�ס��������������"
                        "\n\n" NOR, me);
                damage = me->query("max_qi");
                damage = damage/10 + random(damage/10) + 1;
                me->receive_wound("qi", damage);
                break;
        default:
                break;
        }
    
        // ��������������ȥ��
        room->delete("maze/trap");
        mazeobj->remove_trap(room);
        return;    
}

