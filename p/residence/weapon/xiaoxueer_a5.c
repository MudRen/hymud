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
	      set_name("[1;32mÎäÒíÖ®¶Ü[2;37;0m", ({ "wuyi shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
[1;32mÎäÒíÖ®¶Ü[2;37;0mÕâÊÇÒ»ÃæÓÉ¼«Îª¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÁù½ï¶şÁ½ÈıÇ®µÄ[1;32mÎäÒíÖ®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´¼«Îª¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[33mºÜ¸ß[2;37;0m [32mË®[2;37;0m:[1;32mÄ§Íõ[2;37;0m [31m»ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;35m·ç[2;37;0m:[31m¾«ÖÂ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m¿ªÔª[2;37;0m ÌìĞş:[34mÏ¸Ëé[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
×ÏÊ¯:[32m´Ö²Ú[2;37;0m ÖÜÌì:[32m´Ö²Ú[2;37;0m ³¤Éú:[36m²»´í[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞ¡Ñ©¶ù[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÆ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

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
		set("ownername", "Ğ¡Ñ©¶ù");
		set("value", 16000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",24);
		set("armor_prop/karey",40);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",25);
    set("armor_prop/dodge", 40);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 692);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 437);

    set("wtypeA",4);
    set("wtypeB",0);
    set("wtypeC",9);
    set("wtypeD",10);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",5);
    set("wtypeH",6);
    set("wtypeI",5);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",5);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";