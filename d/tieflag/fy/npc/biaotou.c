 // written by Cheng Bao
// modified by justdoit 05/11/2001
inherit NPC; 
mapping *way;
object cart,F_meng;             //added F_meng by justdoit
object *protector;
mapping *read_table(string);
void del_marks_meng();          //added by justdoit
void give_reward();
void to_rob();
void be_protect();
void create_gangster(object who,string name, int exp); 
void create()
{
    object ob;
    set_name("����ͷ", ({ "biao tou" }) );
    set("gender", "����" );
    set("age", 25);
    set("combat_exp", 100000);
    set("attitude", "friendly");
    set("vendetta_mark", "authority");
    set("per",2);
    set("chat_chance", 5);
    set("chat_msg",({
        "����ͷ�ȵ����������˵������ˡ���\n",
            "����ͷ�ȵ��������߿��ߣ���͵������\n",
            }) );
    set("chat_chance_combat",70);
    set("chat_msg_combat", ({
        "����ͷ�󺰵����������ˣ����˽����ˡ���\n",
            (: be_protect :),
            }) );
        
    set_skill("blade",50);
    set_skill("shortsong-blade",50);
    set_skill("force",40);
    set_skill("parry",150);
    set_skill("dodge",150);
    set_skill("move",800);
    set_skill("fall-steps",50);
    map_skill("dodge","fall-steps");
    map_skill("blade","shortsong-blade");
    map_skill("parry","shortsong-blade");
    setup();
    add_money("coin", 50);
    carry_object(__DIR__"obj/jinzhuang")->wear();
    carry_object("/clone/weapon/gangdao")->wield();
//    carry_object("/obj/food_item/wineskin"); 
}  
int random_move()
{
        mapping exits;
        string *dirs, direction;
        object env;
        
        if( !mapp(exits = environment()->query("exits")) ) return 0;
        
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        command("go " + direction);
        return 1;
}
//overwrite base npc random_move() function
void go()
{
    int i,j;
    object robber;
    string *cmds;
    remove_call_out("go");
    for(i=0;i<sizeof(way);i++)
    {
        if (base_name(environment()) != way[i]["room_file"]) continue;
        cmds=explode(way[i]["cmd_table"],";");
        break;
    }
    robber=present("gangster",environment());
    if (this_object()->is_fighting() || (robber && robber->name()=="ɽ���ٷ�"))
    {
        command("say ��������");
        call_out("go",15);
        return;
    }
    if (random(100)<15)
    {
        to_rob();
        call_out("go",15);
        return;
    }
    if (i>=sizeof(way))
    {   
        random_move();
        cart->move(environment());
        message_vision("�ڳ�¡¡ʻ�˹�����\n",this_object());
        call_out("go",5);
        return;
    }
    for(j=0;j<sizeof(cmds);j++)
        command(cmds[j]);
    cart->move(environment());
    message_vision("�ڳ�¡¡ʻ�˹�����\n",this_object());
    if (way[i]["delay_time"]<0)
    {
        give_reward();
        return;
    }
    call_out("go",way[i]["delay_time"]);
    return;
}        
void be_protect()
{
    int i,j,flag;
    object *inv,*enemy;
        
    inv=all_inventory(environment());
    enemy=query_enemy();
// if one of the protectors wants to kill... then heis out of the loop
    for(j=0;j<sizeof(enemy);j++)
        enemy[j]->delete_temp("protecting"); 
    for (i=0;i<sizeof(inv);i++)
        if (objectp(cart) && inv[i]->query_temp("protecting")==cart)
        {
            flag=1;
            for(j=0;j<sizeof(enemy);j++)
            {
                inv[i]->kill_ob(enemy[j]);
                enemy[j]->kill_ob(inv[i]);
                enemy[j]->remove_killer(this_object());
                remove_killer(enemy[j]);
            }
        }
    if(!flag) return;
    message_vision("$N�����������Ǹ����ϣ���\n",this_object());
        
}        
void get_quest(string file)
{   
    way=read_table(file);
}
void to_rob()
{
    int i;
    object robber;
    int exp;
    object *inv;
    
    exp=this_object()->query("combat_exp");
    inv=all_inventory(environment());
// Some players joined team after getting mission.....
    for (i=0;i<sizeof(inv);i++) {
    if (objectp(cart) && inv[i]->query_temp("protecting")==cart)
       {
         if (inv[i]->query("combat_exp")>exp) 
                exp = inv[i]->query("combat_exp");
        }
    }
        
    message_vision("��Ȼ������һȺ�ٷˣ�\n",this_object());
    for (i=0;i<=random(5)+1;i++)
    {
        robber=new(__DIR__"gangster");
        robber->move(environment());
        robber->set("combat_exp",exp);
        create_gangster(robber,"gangster",exp);
        robber->kill_ob(this_object());
        this_object()->kill_ob(robber);
        robber->set_leader(this_object());
    }
    be_protect();
        
}
        
mapping *read_table(string file)
{
    string *line, *field, *format;
    mapping *data;
    int i, rn, fn; 
    line = explode(read_file(file), "\n");
    data = ({});
    for(i=0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !pointerp(field) ) {
            field = explode( line[i], ":" );
            continue;
        }
        if( !pointerp(format) ) {
            format = explode( line[i], ":" );
            continue;
        }
        break;
    } 
    for( rn = 0, fn = 0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
        sscanf( line[i], format[fn], data[rn][field[fn]] );
        fn = (++fn) % sizeof(field);
        if( !fn ) ++rn;
    }
    return data;
} 
void set_protector(object *prot)
{ protector=prot; } 
object *query_protector()
{ return protector; } 
void set_cart(object dartcart)
{ cart=dartcart; } 
object query_cart()
{ return cart; } 
void die()
{
    object killer;
    object *inv,*pro_team;
    int values;
    int i;
        
    values=0;
    killer=query_temp("last_damage_from");
    if (objectp(cart))
    {
                
        if (arrayp(protector)) 
        {
            values*=2;
            pro_team=({0});
            if (sizeof(pro_team))
            {
                for (i=0;i<sizeof(protector);i++)
                {
                    if (objectp(protector[i])) 
                        pro_team+=({protector[i]});
                }
                if (!sizeof(pro_team))//���ڵ�quit���
                {
                    destruct(cart);
                        del_marks_meng();               //added by justdoit
                    ::die();
                    return;
                }
                values/=sizeof(pro_team);
                for(i=0;i<sizeof(pro_team);i++)
                {
                    if (!objectp(pro_team[i])) continue;
                    if(!intp(pro_team[i]->query("deposit")) )
                        pro_team[i]->set("deposit",0);
                    pro_team[i]->add("deposit",-values);
                    pro_team[i]->add("score",-20);
                    pro_team[i]->save();
                }
                
            }
        }
/*              else
                {
                if(!intp(protector->query("deposit")))
                protector->set("deposit",0);
                protector->add("deposit",-values);
                protector->save();
                }*/
                
        if (objectp(killer))
        {
            command("chat ������"+killer->name()+"�����ˣ�");
            message_vision("$N���ڳ������������е�������\n",killer);
            cart->delete("no_reset"); //allow system to clean it up
            inv=all_inventory(cart);
            for(i=0;i<sizeof(inv);i++)
            {
                values+=inv[i]->value();
                if (userp(killer))
                {
                    inv[i]->move(killer);
                    killer->add("score",-10);
                }
                else
                    destruct(inv[i]);
            }
        }
    }
        del_marks_meng();               //added by justdoit
    ::die();
} 
void give_reward()
{   
    object *inv,*pro_team;
    int values,i,reward; 
                
    reward=random(500)+1000;
    inv=all_inventory(cart);
    for(i=0;i<sizeof(inv);i++)
        values+=inv[i]->value();
                
    if (arrayp(protector)) 
    {
        values/=10;
        pro_team=protector;
        if (sizeof(pro_team))
        {
            values/=sizeof(pro_team);
            reward/=sizeof(pro_team);
            for(i=0;i<sizeof(pro_team);i++)
            {
                if (!objectp(pro_team[i])) continue;
                if(!intp(pro_team[i]->query("deposit")))
                    pro_team[i]->set("deposit",0);
                pro_team[i]->add("deposit",values);
                pro_team[i]->add("combat_exp",reward);
                pro_team[i]->add("potential",reward/10);
                if(!pro_team[i]->query("m_success/����"))
                {
                    pro_team[i]->set("m_success/����",1);
                    pro_team[i]->add("score", 200);
                }
                pro_team[i]->save();
            }
        }
/*              else
                {
                if(!intp(protector->query("deposit")) )
                protector->set("deposit",0);
                protector->set("deposit",protector->query("deposit")+values);
                protector->add("combat_exp",reward);                    
                protector->add("score",reward/100);                        
                protector->save();
                protector->add("potential",reward/10);          
                }*/
    }
        
    destruct(cart);
    inv=all_inventory(environment()); 
    for (i=0;i<sizeof(inv);i++)
        if (inv[i]->query_temp("protecting")==cart && !userp(inv[i]))
            destruct(inv[i]); 
        del_marks_meng();               //added by justdoit
    destruct(this_object());
        
    return;
} 
//added by justdoit, in order to delete marks on meng
void del_marks_meng()
{
        F_meng = find_living("meng");
        if(environment(F_meng))
        {
                F_meng->delete("marks/gived");
        }
}
//end 
void go_now()
{
    call_out("go",10);
}  
void create_gangster(object who,string name, int exp)
{
        int level;
        level=100+130*(exp-1000000)/5500000;
        if (exp<1000000) level=100;
        if (exp>6400000) level=230;
        level=level*level/100;
        if (name=="biao") {
                who->set("str",10+random(level/15));
                who->set("agi",10+random(level/8));
                who->set("cor",20+random(15));
                who->set("max_qi",1000+random(level*level/40));
                who->set("eff_qi",who->query("max_qi"));
                who->set("qi",who->query("max_qi"));
                who->set_skill("hammer", 70 + random(level/2));
                who->set_skill("parry", 70 + random(level/2));
                who->set_skill("dodge", 70 + random(level/2));
                who->set_skill("move", 70 + random(level/2));
                who->set_skill("changquan",50+random(level/2));
                who->set_skill("unarmed",70 + random(level/2));
        }
        if (name=="gangster") {
                who->set("str",20+random(level/12));
                who->set("agi",10+random(level/8));
                who->set("cor",20+random(15));
                who->set("max_qi",2500+random(level*level/40));
                who->set("eff_qi",who->query("max_qi"));
                who->set("qi",who->query("max_qi"));
                who->set("max_sen",who->query("max_qi")/2);
                who->set("max_jing",who->query("max_qi")/2);
                who->set("eff_sen",who->query("max_sen"));
                who->set("sen",who->query("max_sen"));
                who->set("eff_jing",who->query("max_jing"));
                who->set("jing",who->query("max_jing"));
                who->set_skill("parry", 70 + random(level/2));
                who->set_skill("dodge", 70 + random(level/2));
                who->set_skill("move", 70 + random(level/2));
                who->set_skill("blade",70+random(level/2));
                who->set_skill("fall-steps",70+random(level/2));
                who->set_skill("unarmed",70+ random(level/2));
                who->set_skill("yue-strike",50+random(level/8));
                who->set_skill("shortsong-blade",50+random(level/8));
                who->set("max_neili",1000+random(level*level/40));
                who->set("neili",who->query("max_force"));
                who->set("force_factor",30+random(level/8));
        } 
}
