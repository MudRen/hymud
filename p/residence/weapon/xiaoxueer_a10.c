#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;32m����֮��װ[2;37;0m", ({ "wanpan cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;32m����֮��װ[2;37;0m����һ�����ޱȼ�Ӳ��[1;33m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ��ؾŽ������Ǯ��[1;32m����֮��װ[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȼ�̣�����[35m�������[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;32mħ��[2;37;0m [36mľ[2;37;0m:[1;31m��˫[2;37;0m [31m��[2;37;0m:[1;36m����[2;37;0m [33m��[2;37;0m:[33m�ܸ�[2;37;0m [1;34m��[2;37;0m:[1;31m��˫[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��˫[2;37;0m ����:[34mϸ��[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[35m��׼[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[33m�ܸ�[2;37;0m ����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mСѩ��[2;37;0m ������һЩ�� [1;32mצ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xiaoxueer");
		set("ownername", "Сѩ��");
		set("value", 16000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",40);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 55);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 985);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 41);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 501);

    set("wtypeA",9);
    set("wtypeB",12);
    set("wtypeC",5);
    set("wtypeD",7);
    set("wtypeE",4);
    set("wtypeF",6);
    set("wtypeG",5);
    set("wtypeH",12);
    set("wtypeI",6);
    set("wtypeJ",6);
    set("wtypeK",1);
    set("wtypeL",5);
    
    
                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";