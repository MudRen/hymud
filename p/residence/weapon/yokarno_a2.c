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
	      set_name("[1;31mÚØ≥œ≥§≈€[2;37;0m", ({ "bad cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "º˛");
		set("long", @LONG
÷Ò÷Æ∑˛◊∞[2;37;0m’‚ «“ªº˛”…∑«≥£º·”≤µƒ[32m«‡Õ≠[2;37;0mº”…œ[1;37m√ﬁª®[2;37;0m÷∆≥…£¨÷ÿ“ªΩÔ∞À¡Ω¡„«Æµƒ[1;31m÷Ò÷Æ∑˛◊∞[2;37;0m°£
◊€∫œ∆¿º€[32mæ´÷¬œ∏√¿[2;37;0m ø¥∆¿¥∑«≥£º·πÃ£¨æﬂ”–[34m≤ª¥Ì[2;37;0mµƒ∑¿ª§¡¶£°
…œ√ÊªπøÃ¡À“ª–©∑˚◊÷£∫
º·”≤:[34mœ∏ÀÈ[2;37;0m «…÷∆:[33m“ª∞„[2;37;0m 
◊œ Ø:[33m“ª∞„[2;37;0m ≤ª¿œ:[32mº´≤Ó[2;37;0m 
“‘º∞“ª≈≈π≈◊≠◊÷°æ [1;32m‘∆‘¬Ù·[2;37;0m °ø°£∫Õ“ª–©°æ [1;32mƒ⁄π¶[2;37;0m °øµƒºº«…°£

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
		set("ownername", "‘∆‘¬Ù·");
		set("value", 2000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 9);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 444);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 4);
    set("armor_prop/jingli", 4);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",9);
    set("wtypeE",0);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "force",
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