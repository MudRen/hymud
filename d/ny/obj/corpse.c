
// corpse.c

inherit ITEM;

int decayed;

void create()
{
        set_name("����ʬ��", ({ "corpse" }) );
        set("long", "����һ������ʬ�塣\n");
        set("unit", "��" );
        decayed = 0;
        if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
        decayed = phase;
        switch(phase) {
                case 1:
                        say( query("name") + 
"��ʼ�����ˣ�����һ�����ŵĶ����\n" );
                        switch(query("gender")) {
                                case "����":
                                        set_name("���õ���ʬ", ({ "corpse", 
"ʬ��" }) );
                                case "Ů��":
                                        set_name("���õ�Ůʬ", ({ "corpse", 
"ʬ��" }) );
                                default:
                                        set_name("���õ�ʬ��", ({ "corpse", 
"ʬ��" }) );
                        }
                        set("long",     
"���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
                        say( query("name") + "���紵Ǭ�ˣ����һ�ߺ��ǡ�\n" );
                        set_name("һ�߿�Ǭ�ĺ���", ({ "skeleton", "����" }) 
);
                        set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
                        say( "һ��紵������" + query("name") + 
"���ɹǻҴ�ɢ�ˡ�\n" );
                        if( environment() ) {
                                object *inv;
                                int i;
                                
                                inv = all_inventory(this_object());
                                for(i=0; i<sizeof(inv); i++) 
inv[i]->move(environment());
                        }
                        destruct(this_object());
                        break;
        }
}

object animate(object who, int time)
{
        object zombie,corpse;
        corpse=this_object();

        if( !environment() ) return 0;

        seteuid(getuid());
        zombie = new("/obj/npc/zombie");
        zombie->set_name( (string)query("victim_name") + "�Ľ�ʬ", ({ 
"zombie" }) );
    zombie->set("combat_exp", corpse->query("combat_exp"));
    zombie->set("max_force", corpse->query("max_force"));
    zombie->set("force_factor", corpse->query("force_factor"));
    zombie->set("force", corpse->query("force"));
    zombie->set("max_kee", corpse->query("max_kee"));
    zombie->set_skill("unarmed", corpse->query("unarmed"));
    zombie->set_skill("dodge", corpse->query("dodge"));
    zombie->set("kee", corpse->query("maxkee"));
    zombie->set("eff_kee", corpse->query("max_kee"));
        zombie->move(environment());
        zombie->animate(who, time);

        destruct(this_object());
        return zombie;
}
 
