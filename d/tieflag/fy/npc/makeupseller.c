 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("����", ({ "fang" }) );
        set("gender", "Ů��" );
        set("age", 29);
        set("title", HIY "ǧ"+ HIR "��" + HIM "��" + HIC"��"NOR);
        set("long",
                "��λ�����ɧ���ϰ�������������۶���\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ({
                __DIR__"obj/yanzhi",
                __DIR__"obj/bao",
                __DIR__"obj/huabag",
                __DIR__"obj/pozhi",
        }));
        set_skill("unarmed",200);
        set_skill("dodge",200);
        setup();
        carry_object(__DIR__"obj/wch_skirt")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
message_vision("$NЦ��˵�������ʲô���У���Щ��ȥ����������˰ɡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$NЦ�����˵������λ"+RANK_D->query_respect(ob)+
"Ҫ��ʲô��\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N��һ���������������$n��\n",this_object(),ob);
        }
} 
int accept_object(object who, object ob)
{
        string tmpname;
        string err;
        object newmask;
        object rope,*obj;
        int i;
        string gender, name, id;
        string newfile;
        if(ob->query("skull")){
                if(!who->query("m_success/�䵱���ŵ�����")) {
                        return 0;
                }
                /*obj = all_inventory(ob);
                for(i=sizeof(obj)-1;i>=0;i--)  {
                        if(obj[i]->query("silk")) {
 give out a mask
                              destruct(object[i]);*/
                         else {       newmask = new(__DIR__"obj/headmask");
                                newmask->move(who);
                        message_vision("$N���ĵ�����$nһ��������\n",this_object(), who);
                                return 1;
                        }
                }
               // command("say ����������ʲô�ã�����Ҫ����������ճɵĻҲſ��Դ���ͷ��������ߡ�\n");
                //return 0;
                
        
        if(ob->name() != "�������ֽƬ") return 0;
       // tmpname = "/open/tempmask"+sprintf("%d",time());
        message_vision("$N����$n���齩Ӳ��Ц��Ц������\n",this_object(),who);
   gender = (string)ob->query("targetgender");
        name = (string)ob->query("targetname");
        id = (string)ob->query("targetid");
        if( !stringp(id) ) return 0;
        if( !find_living(id)) return 0;
        if( !stringp(gender)) return 0;
        if( !stringp(name) ) return 0;
        if ((string)gender != "����" && (string)gender != "Ů��")
                return 0;
        id = capitalize(id);
//        newfile = read_file("/obj/item/orig_mask.o");
        if( !newfile) return 0;
        seteuid(ROOT_UID);
  //      newfile = replace_string( newfile, "����", gender);
    //    newfile = replace_string( newfile, "maskman", id);
      //  newfile = replace_string( newfile, "������", name);
        //if( !newfile) return 0;
        //tmpname = tmpname + who->query("id") + ".c";
        //if( !write_file(tmpname, newfile, 1))
//      if(!write_file(tmpname, newfile, 1))
                return 0;
        newmask = new(__DIR__"obj/headmask");
   
        if( !newmask) return 0;
        newmask->move(who);
        message_vision("$N���ĵ�����$nһ��������\n",this_object(), who);
        seteuid(getuid());
                return 1;
} 

           
