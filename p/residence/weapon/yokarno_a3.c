#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;31m������[2;37;0m", ({ "bad armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
��֮����[2;37;0m����һ���ɻ����Ӳ��[32m��ͭ[2;37;0m����[1;37m�޻�[2;37;0m�Ƴɣ���һ��������Ǯ��[1;31m��֮����[2;37;0m��
�ۺ�����[32m����ϸ��[2;37;0m �����������̣�����[36mһ��[2;37;0m�ķ�������
������˼����ŷ��ţ�
[33m��[2;37;0m:[31m����[2;37;0m [37m��[2;37;0m:[34mϸ��[2;37;0m [1;36m��[2;37;0m:[31m����[2;37;0m [1;31mħ[2;37;0m:[34mϸ��[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[34mϸ��[2;37;0m ����:[32m����[2;37;0m 
��ʯ:[33mһ��[2;37;0m ����:[32m����[2;37;0m ����:[32m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m������[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yokarno");
		set("ownername", "������");
		set("value", 2000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 9);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 280);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 3);
    set("armor_prop/jing", 4);
    set("armor_prop/jingli", 4);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",6);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",2);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 2);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";