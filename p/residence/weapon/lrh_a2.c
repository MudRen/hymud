#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;31mÇïÓêÖ®¶Ü[2;37;0m", ({ "good shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
ÇïÓêÖ®¶Ü[2;37;0mÕâÊÇÒ»ÃæÓÉ¼«Îª¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0m¼ÓÉÏ[1;37m²ÏË¿[2;37;0mÖÆ³É£¬ÖØÎå½ï¾ÅÁ½ÎåÇ®µÄ[1;31mÇïÓêÖ®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´¼«Îª¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;36mÍêÃÀ[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [33mÍÁ[2;37;0m:[1;36mÍêÃÀ[2;37;0m [1;34mµç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÌìÊ¥[2;37;0m ÌìÔ¨:[36m²»´í[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
°×Ê¯:[34mÏ¸Ëé[2;37;0m ³¤Éú:[33mÒ»°ã[2;37;0m ²»ÀÏ:[34mÏ¸Ëé[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÒÇÂÀ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¹÷·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lrh");
		set("ownername", "ÒÇÂÀ");
		set("value", 9000);
		set("armor_prop/intelligence",24);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",17);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 193);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 10);
    set("armor_prop/jing", 25);
    set("armor_prop/jingli", 25);
    set("armor_prop/damage", 0);

    set("wtypeA",7);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",5);
    set("wtypeE",7);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",9);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";